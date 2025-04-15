package com.finance.finance.service;

import com.finance.finance.dto.BuyStockDto;
import com.finance.finance.dto.SellStockDto;
import com.finance.finance.dto.StockSimulatorDto;
import com.finance.finance.entity.MyStocksEntity;
import com.finance.finance.entity.OrderEntity;
import com.finance.finance.entity.User;
import com.finance.finance.entity.WalletEntity;
import com.finance.finance.repository.MyStocksRepository;
import com.finance.finance.repository.OrderRepository;
import com.finance.finance.repository.UserRepository;
import com.finance.finance.repository.WalletRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class OrderService {

    private final UserRepository userRepository;
    private final WalletRepository walletRepository;
    private final OrderRepository orderRepository;
    private final SimulatorService simulatorService;
    private final MyStocksRepository myStocksRepository;

    public OrderService(UserRepository userRepository,
                        SimulatorService simulatorService,
                        OrderRepository orderRepository,
                        WalletRepository walletRepository,
                        MyStocksRepository myStocksRepository) {
        this.userRepository = userRepository;
        this.simulatorService = simulatorService;
        this.orderRepository = orderRepository;
        this.walletRepository = walletRepository;
        this.myStocksRepository = myStocksRepository;
    }

    public String buyStock(BuyStockDto dto) {
        User user = userRepository.findById(dto.userId())
                .orElseThrow(() -> new RuntimeException("User Not Found"));

        WalletEntity wallet = user.getWallet();

        MyStocksEntity walletStock = myStocksRepository.findByWalletAndTicker(wallet, dto.ticker())
                .orElseGet(() -> new MyStocksEntity(wallet, dto.ticker(), 0));

        walletStock.setQuantity(walletStock.getQuantity() + dto.quantity());
        myStocksRepository.save(walletStock);

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
                .orElseThrow(() -> new RuntimeException("User Not Found"));

        WalletEntity wallet = user.getWallet();

        StockSimulatorDto stock = simulatorService.getStock(dto.ticker());
        if (stock == null) {
            throw new RuntimeException("Stock Not Found");
        }

        MyStocksEntity walletStock = myStocksRepository.findByWalletAndTicker(wallet, dto.ticker())
                .orElseThrow(() -> new RuntimeException("You don't own this stock"));

        if (walletStock.getQuantity() < dto.quantity()) {
            throw new RuntimeException("Not enough shares to sell");
        }
        int updatedQuantity = walletStock.getQuantity() - dto.quantity();
        if (updatedQuantity == 0) {
            myStocksRepository.delete(walletStock);
        } else {
            walletStock.setQuantity(updatedQuantity);
            myStocksRepository.save(walletStock);
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
    public List<OrderEntity> getOrdersByUserId(Integer userId) {
        User user = userRepository.findById(userId)
                .orElseThrow(() -> new RuntimeException("User Not Found"));
        WalletEntity wallet = user.getWallet();
        return orderRepository.findByWallet(wallet);
    }
}
