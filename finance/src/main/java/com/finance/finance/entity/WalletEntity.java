package com.finance.finance.entity;

import com.fasterxml.jackson.annotation.JsonIgnore; // Certifique-se de importar a anotação correta
import jakarta.persistence.*;

@Entity
@Table(name = "wallets")
public class WalletEntity {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    @Column(nullable = false)
    private Double balance;

    @OneToOne
    @JoinColumn(name = "user_id", nullable = false, unique = true)
    @JsonIgnore 
    private User user;

    public WalletEntity() {}

    public WalletEntity(User user, Double initialBalance) {
        this.user = user;
        this.balance = initialBalance;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Double getBalance() {
        return balance;
    }

    public void setBalance(Double balance) {
        this.balance = balance;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }
}
