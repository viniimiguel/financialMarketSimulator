package com.finance.finance.entity;

import jakarta.persistence.*;

@Entity
@Table(name = "My_wallet")
public class MyStocksEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    @ManyToOne
    @JoinColumn(name = "wallet_id", nullable = false)
    private WalletEntity wallet;

    @Column(nullable = false)
    private String ticker;

    @Column(nullable = false)
    private Integer quantity;

    public MyStocksEntity(WalletEntity wallet, String ticker, Integer quantity) {
        this.wallet = wallet;
        this.ticker = ticker;
        this.quantity = quantity;
    }

    public MyStocksEntity() {

    }


    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public WalletEntity getWallet() {
        return wallet;
    }

    public void setWallet(WalletEntity wallet) {
        this.wallet = wallet;
    }

    public String getTicker() {
        return ticker;
    }

    public void setTicker(String ticker) {
        this.ticker = ticker;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }

    public MyStocksEntity(Integer id, Integer quantity, String ticker, WalletEntity wallet) {
        this.id = id;
        this.quantity = quantity;
        this.ticker = ticker;
        this.wallet = wallet;
    }
}
