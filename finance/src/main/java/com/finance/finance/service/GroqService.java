package com.finance.finance.service;

import com.finance.finance.dto.GroqDto;
import org.springframework.stereotype.Service;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Service
public class GroqService {

    private final Map<String, GroqDto> groqData = new ConcurrentHashMap<>();
    private volatile String lastNoticeKey;

    public String createNotice(GroqDto groqDto) {
        groqData.put(groqDto.notice(), groqDto);
        lastNoticeKey = groqDto.notice();
        System.out.println("notice: " + groqDto.notice());
        return "Notice created successfully with notice " + groqDto.notice();
    }

    public Map<String, GroqDto> getAllNotices() {
        return groqData;
    }

    public GroqDto getLatestNotice() {
        return lastNoticeKey != null ? groqData.get(lastNoticeKey) : null;
    }
}
