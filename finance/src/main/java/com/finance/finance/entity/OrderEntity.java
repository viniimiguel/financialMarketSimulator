package com.finance.finance.entity;

import jakarta.persistence.*;
import java.time.LocalDateTime;

@Entity
@Table(name = "orders")
public class OrderEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    @Column(nullable = false)
    private String type;

    @Column(nullable = false)
    private String ticker;

    @Column(nullable = false)
    private Double price;

    @Column(nullable = false)
    private Integer quantity;

    private LocalDateTime timestamp;

    @ManyToOne
    @JoinColumn(name = "wallet_id", nullable = false)
    private WalletEntity wallet;

    public OrderEntity() {}

    public OrderEntity(String type, String ticker, Double price, Integer quantity, WalletEntity wallet) {
        this.type = type;
        this.ticker = ticker;
        this.price = price;
        this.quantity = quantity;
        this.wallet = wallet;
        this.timestamp = LocalDateTime.now();
    }

    public Integer getId() {
        return id;
    }

    public String getType() {
        return type;
    }

    public String getTicker() {
        return ticker;
    }

    public Double getPrice() {
        return price;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public LocalDateTime getTimestamp() {
        return timestamp;
    }

    public WalletEntity getWallet() {
        return wallet;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setTicker(String ticker) {
        this.ticker = ticker;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public void setWallet(WalletEntity wallet) {
        this.wallet = wallet;
    }
}
