package com.finance.finance.controller;

import com.finance.finance.dto.WalletDto;
import com.finance.finance.entity.MyStocksEntity;
import com.finance.finance.entity.WalletEntity;
import com.finance.finance.service.MyWalletService;
import com.finance.finance.service.WalletService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@RestController
@RequestMapping("/wallet")
public class WalletController {
    private final WalletService walletService;
    private final MyWalletService myWalletService;

    public WalletController(WalletService walletService, MyWalletService myWalletService) {
        this.walletService = walletService;
        this.myWalletService = myWalletService;
    }

    @PostMapping("/create")
    public ResponseEntity<WalletDto> createWallet(@RequestBody WalletDto walletDto) {
        WalletEntity walletEntity = walletService.createWallet(walletDto);
        return ResponseEntity.ok(new WalletDto(walletEntity.getBalance(), walletEntity.getUser()));
    }

    @GetMapping("/get/{id}")
    public WalletEntity getWalletByUserId(@PathVariable("id") Integer userId) {
        return walletService.getWallet(userId);
    }

    @GetMapping("/get/my-wallet/{walletId}")
    public List<MyStocksEntity> getMyStocksByWalletId(@PathVariable("walletId") Integer walletId) {
        return myWalletService.getMyStocksByWalletId(walletId);
    }
}
