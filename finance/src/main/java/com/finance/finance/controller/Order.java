package com.finance.finance.controller;

import com.finance.finance.dto.BuyStockDto;
import com.finance.finance.dto.SellStockDto;
import com.finance.finance.service.OrderService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/orders")
public class Order {

    private OrderService orderService;

    public Order(OrderService orderService) {
        this.orderService = orderService;
    }

    @PostMapping("/buy")
    public ResponseEntity<String> buyStock(@RequestBody BuyStockDto buyStockDto) {
        try{
            String response = orderService.buyStock(buyStockDto);
            return ResponseEntity.ok(response);
        } catch(RuntimeException e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    @PostMapping("/sell")
    public ResponseEntity<String> sellStock(@RequestBody SellStockDto sellStockDto) {
        try{
            String response = orderService.sellStock(sellStockDto);
            return ResponseEntity.ok(response);
        }catch (RuntimeException e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }
}