package controller;

import dto.StockSimulatorDto;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import service.SimulatorService;

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
}
