package com.finance.finance.service;

import com.finance.finance.dto.BuyStockDto;
import com.finance.finance.dto.SellStockDto;
import com.finance.finance.dto.StockSimulatorDto;
import com.finance.finance.entity.OrderEntity;
import com.finance.finance.entity.User;
import com.finance.finance.entity.WalletEntity;
import com.finance.finance.repository.OrderRepository;
import com.finance.finance.repository.UserRepository;
import com.finance.finance.repository.WalletRepository;
import org.springframework.stereotype.Service;

@Service
public class OrderService {

    private UserRepository userRepository;

    private WalletRepository walletRepository;

    private OrderRepository orderRepository;

    private SimulatorService simulatorService;

    public OrderService(UserRepository userRepository, SimulatorService simulatorService, OrderRepository orderRepository, WalletRepository walletRepository) {
        this.userRepository = userRepository;
        this.simulatorService = simulatorService;
        this.orderRepository = orderRepository;
        this.walletRepository = walletRepository;
    }

    public String buyStock(BuyStockDto dto) {
        User user = userRepository.findById(dto.userId())
                .orElseThrow(() -> new RuntimeException("User Not Found"));

        WalletEntity wallet = user.getWallet();

        StockSimulatorDto stock = simulatorService.getStock(dto.ticker());
        if (stock == null) {
            throw new RuntimeException("Stock Not Found");
        }

        double totalCost = stock.price() * dto.quantity();
        if (wallet.getBalance() < totalCost) {
            throw new RuntimeException("Not enough balance");
        }

        wallet.setBalance(wallet.getBalance() - totalCost);
        OrderEntity order = new OrderEntity(
                "BUY",
                dto.ticker(),
                stock.price(),
                dto.quantity(),
                wallet
        );
        orderRepository.save(order);
        walletRepository.save(wallet);

        return "Buy accomplished";
    }

    public String sellStock(SellStockDto dto) {
        User user = userRepository.findById(dto.userId())
                .orElseThrow(()-> new RuntimeException("User Not Found"));

        WalletEntity wallet = user.getWallet();

        StockSimulatorDto stock = simulatorService.getStock(dto.ticker());
        if (stock == null) {
            throw new RuntimeException("Stock Not Found");
        }

        Integer currentyQuantity = orderRepository.getNetStockQuantity(wallet.getId(), dto.ticker());
        if(currentyQuantity == null || currentyQuantity < dto.quantity()) {
            throw new RuntimeException("Not enough shares to sell");
        }

        double totalGain = stock.price() * dto.quantity();

        wallet.setBalance(wallet.getBalance() + totalGain);

        OrderEntity order = new OrderEntity(
                "SELL",
                dto.ticker(),
                stock.price(),
                dto.quantity(),
                wallet
        );

        orderRepository.save(order);
        walletRepository.save(wallet);
        return "Sell accomplished";

    }

}
