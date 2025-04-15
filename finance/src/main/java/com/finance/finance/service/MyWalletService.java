package com.finance.finance.service;

import com.finance.finance.entity.MyStocksEntity;
import com.finance.finance.repository.MyStocksRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MyWalletService {

    private final MyStocksRepository myStocksRepository;

    public MyWalletService(MyStocksRepository myStocksRepository) {
        this.myStocksRepository = myStocksRepository;
    }
    public List<MyStocksEntity> getMyStocksByWalletId(Integer walletId) {
        return myStocksRepository.findByWalletId(walletId);
    }
}
