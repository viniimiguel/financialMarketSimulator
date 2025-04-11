package com.finance.finance.dto;
public record StockSimulatorDto(String ticker, String companyName, Double price, Double variation, String country, String sector) {
}