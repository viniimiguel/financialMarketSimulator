package com.finance.finance.service;

import com.finance.finance.dto.StockSimulatorDto;
import org.springframework.stereotype.Service;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;
import java.util.Map;

@Service
public class SimulatorService {

    private final Map<String, StockSimulatorDto> stockData = new ConcurrentHashMap<>();

    public String createStock(StockSimulatorDto stockSimulatorDto) {
        stockData.put(stockSimulatorDto.ticker(), stockSimulatorDto);

        System.out.println("ticker: " + stockSimulatorDto.ticker());
        System.out.println("companyName: " + stockSimulatorDto.companyName());
        System.out.println("price: " + stockSimulatorDto.price());
        System.out.println("variation: " + stockSimulatorDto.variation() + "%");
        System.out.println("Cou tenho que fazer ountry: " + stockSimulatorDto.country());
        System.out.println("Sector: " + stockSimulatorDto.sector());

        return "Stock created successfully with ticker " + stockSimulatorDto.ticker();
    }

    public StockSimulatorDto getStock(String ticker) {
        return stockData.get(ticker);
    }

    public Collection<StockSimulatorDto> getAllStocks() {
        return stockData.values();
    }


}
