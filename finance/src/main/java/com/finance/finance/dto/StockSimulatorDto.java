package com.finance.finance.dto;
public record StockSimulatorDto(String ticker, String companyName, Double price, Integer shares, Integer demand, Double variation) {
}