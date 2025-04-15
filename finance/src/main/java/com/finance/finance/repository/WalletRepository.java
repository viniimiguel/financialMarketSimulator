package com.finance.finance.repository;

import com.finance.finance.entity.WalletEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface WalletRepository extends JpaRepository<WalletEntity, Integer> {
    boolean existsByUserId(Integer id);
    Optional<WalletEntity> findByUserId(Integer userId);
}
