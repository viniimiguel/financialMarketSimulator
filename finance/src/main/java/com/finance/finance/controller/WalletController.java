package com.finance.finance.controller;

import com.finance.finance.dto.WalletDto;
import com.finance.finance.entity.WalletEntity;
import com.finance.finance.service.WalletService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;


@RestController
@RequestMapping("/wallet")
public class WalletController {

    private WalletService walletService;

    public WalletController(WalletService walletService) {
        this.walletService = walletService;
    }

    @PostMapping("/create")
    public ResponseEntity<WalletDto> createWallet(@RequestBody WalletDto walletDto) {
        WalletEntity walletEntity = walletService.createWallet(walletDto);
        return ResponseEntity.ok(new WalletDto(walletEntity.getBalance(), walletEntity.getUser()));
    }
}
