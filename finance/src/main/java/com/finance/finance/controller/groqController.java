package com.finance.finance.controller;

import com.finance.finance.dto.GroqDto;
import com.finance.finance.service.GroqService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

@RestController
@RequestMapping("/api/groq")
public class groqController {

    private final GroqService groqService;

    public groqController(GroqService groqService) {
        this.groqService = groqService;
    }

    @PostMapping("/notice")
    public ResponseEntity<String> createNotice(@RequestBody GroqDto groqDto) {
        String response = groqService.createNotice(groqDto);
        return ResponseEntity.status(HttpStatus.CREATED).body(response);
    }

    @GetMapping("/get/notices")
    public ResponseEntity<Map<String, GroqDto>> getAllNotices() {
        Map<String, GroqDto> allNotices = groqService.getAllNotices();
        return ResponseEntity.ok(allNotices);
    }
    @GetMapping("/get/notice")
    public ResponseEntity<String> getLatestNotice() {
        GroqDto latestNotice = groqService.getLatestNotice();
        if (latestNotice != null) {
            return ResponseEntity.ok(latestNotice.notice());
        } else {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("No notice found");
        }
    }

}

