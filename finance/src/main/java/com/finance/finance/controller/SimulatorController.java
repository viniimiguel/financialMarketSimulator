package com.finance.finance.controller;

import com.finance.finance.dto.StockSimulatorDto;
import com.finance.finance.service.SimulatorService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.Collection;


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

    @GetMapping("/stock/{ticker}")
    public ResponseEntity<StockSimulatorDto> getStock(@PathVariable String ticker) {
        StockSimulatorDto dto = simulatorService.getStock(ticker);
        if(dto != null){
            return ResponseEntity.ok(dto);
        } else{
            return ResponseEntity.notFound().build();
        }

    }

    @GetMapping("/stock/all")
    public ResponseEntity<Collection<StockSimulatorDto>> getAllStocks(){
        Collection<StockSimulatorDto> allStocks = simulatorService.getAllStocks();
        return ResponseEntity.ok(allStocks);
    }
    }