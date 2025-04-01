package com.finance.finance.service;

import com.finance.finance.dto.StockSimulatorDto;
import org.springframework.stereotype.Service;

@Service
public class SimulatorService {

    public String createStock(StockSimulatorDto stockSimulatorDto) {

        System.out.println("ticker: " + stockSimulatorDto.ticker());
        System.out.println("companyName: " + stockSimulatorDto.companyName());
        System.out.println("price: " + stockSimulatorDto.price());
        System.out.println("variation: " + stockSimulatorDto.variation());

        return "Stock created successfully with ticker" + stockSimulatorDto.ticker();
    }
}