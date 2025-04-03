package com.finance.finance.dto;

import com.finance.finance.entity.User;

public record WalletDto(Double balance, User user) {
}
