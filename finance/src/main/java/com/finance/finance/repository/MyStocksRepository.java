package com.finance.finance.repository;

import com.finance.finance.entity.MyStocksEntity;
import com.finance.finance.entity.WalletEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;

@Repository
public interface MyStocksRepository extends JpaRepository<MyStocksEntity, Integer> {

    Optional<MyStocksEntity> findByWalletAndTicker(WalletEntity wallet, String ticker);
    List<MyStocksEntity> findByWalletId(Integer walletId);

}
