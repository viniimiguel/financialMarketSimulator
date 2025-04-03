package com.finance.finance.service;

import com.finance.finance.dto.WalletDto;
import com.finance.finance.entity.User;
import com.finance.finance.entity.WalletEntity;
import com.finance.finance.repository.UserRepository;
import com.finance.finance.repository.WalletRepository;
import org.springframework.stereotype.Service;

@Service
public class WalletService {

    private WalletRepository walletRepository;

    private UserRepository userRepository;

    public WalletService(WalletRepository walletRepository, UserRepository userRepository) {
        this.walletRepository = walletRepository;
        this.userRepository = userRepository;
    }

    public WalletEntity createWallet(WalletDto walletDto) {
        User user = userRepository.findById(walletDto.user().getId())
                .orElseThrow(()-> new RuntimeException("User Not Found"));

        if(walletRepository.existsByUserId(walletDto.user().getId())) {
            throw new RuntimeException("Wallet already exists");
        }

        WalletEntity wallet = new WalletEntity(user, walletDto.balance());
        return walletRepository.save(wallet);
    }
}
