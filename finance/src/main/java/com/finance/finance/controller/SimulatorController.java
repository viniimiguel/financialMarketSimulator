package com.finance.finance.controller;

import com.finance.finance.dto.StockSimulatorDto;
import com.finance.finance.service.SimulatorService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.mvc.method.annotation.SseEmitter;

import java.io.IOException;
import java.util.Collection;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;


@RestController
@RequestMapping("/api/simulator")
public class SimulatorController {

    private final SimulatorService simulatorService;

    public SimulatorController(SimulatorService simulatorService) {
        this.simulatorService = simulatorService;
    }

    @PostMapping("/stock")
    public ResponseEntity<String> createStock(@RequestBody StockSimulatorDto stockSimulatorDto) {
        String response = simulatorService.createStock(stockSimulatorDto);
        return ResponseEntity.status(HttpStatus.CREATED).body(response);
    }

    @GetMapping("/stock/random")
    public SseEmitter streamRandomStocks(@RequestParam(defaultValue = "4") int count) {
        SseEmitter emitter = new SseEmitter(0L);
        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);

        scheduler.scheduleAtFixedRate(() -> {
            try {
                List<StockSimulatorDto> randomStocks = simulatorService.getRandomStocks(count);
                emitter.send(SseEmitter.event().data(randomStocks));
            } catch (IOException e) {
                emitter.completeWithError(e);
            }
        }, 0, 1, TimeUnit.SECONDS);

        emitter.onCompletion(scheduler::shutdown);
        emitter.onError(throwable -> {
            System.out.println("SSE stream error: " + throwable.getMessage());
            scheduler.shutdown();
        });
        emitter.onTimeout(scheduler::shutdown);

        return emitter;
    }

    @GetMapping("/stock/all")
    public SseEmitter streamAllStocks() {
        SseEmitter emitter = new SseEmitter(0L);
        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);

        scheduler.scheduleAtFixedRate(() -> {
            try {
                Collection<StockSimulatorDto> allStocks = simulatorService.getAllStocks();
                emitter.send(SseEmitter.event().data(allStocks));
            } catch (IOException e) {
                emitter.completeWithError(e);
            }
        }, 0, 1, TimeUnit.SECONDS);

        emitter.onCompletion(scheduler::shutdown);
        emitter.onError(throwable -> {
            System.out.println("SSE stream error: " + throwable.getMessage());
            scheduler.shutdown();
        });
        emitter.onTimeout(scheduler::shutdown);
        return emitter;
    }
}
