package com.finance.finance.repository;

import com.finance.finance.entity.OrderEntity;
import com.finance.finance.entity.WalletEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface OrderRepository extends JpaRepository<OrderEntity, Integer> {

    @Query("SELECT SUM(CASE WHEN o.type = 'BUY' THEN o.quantity ELSE -o.quantity END) " +
            "FROM OrderEntity o WHERE o.wallet.id = :walletId AND o.ticker = :ticker")
    Integer getNetStockQuantity(@Param("walletId") Integer walletId, @Param("ticker") String ticker);

    List<OrderEntity> findByWallet(WalletEntity wallet);
}
