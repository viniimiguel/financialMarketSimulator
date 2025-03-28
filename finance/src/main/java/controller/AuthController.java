package controller;

import dto.LoginRequestDto;
import dto.RegisterRequestDto;
import dto.ResponseDto;
import entity.User;
import org.springframework.http.ResponseEntity;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import repository.UserRepository;
import security.TokenService;

import java.util.Optional;

@RestController
@RequestMapping("/auth")
public class AuthController {

    private final UserRepository userRepository;
    private final PasswordEncoder passwordEncoder;
    private final TokenService tokenService;

    public AuthController(UserRepository userRepository, PasswordEncoder passwordEncoder, TokenService tokenService) {
        this.userRepository = userRepository;
        this.passwordEncoder = passwordEncoder;
        this.tokenService = tokenService;
    }
    @PostMapping("/login")
    public ResponseEntity login(@RequestBody LoginRequestDto body) {
        User user = this.userRepository.findByEmail(body.email()).orElseThrow(() -> new RuntimeException("User not found"));
        if(passwordEncoder.matches(body.password(), user.getPassword())) {
            String token = tokenService.generateToken(user);
            return ResponseEntity.ok(new ResponseDto(user.getName(), token));
        }
        return ResponseEntity.badRequest().build();
    }
    @PostMapping("/register")
    public ResponseEntity register(@RequestBody RegisterRequestDto body) {
        Optional<User> user = this.userRepository.findByEmail(body.email());
        if(user.isEmpty()){
            User newUser = new User();
            newUser.setPassword(passwordEncoder.encode(body.password()));
            newUser.setEmail(body.email());
            newUser.setName(body.name());
            this.userRepository.save(newUser);
            String token = tokenService.generateToken(newUser);
            return ResponseEntity.ok(new ResponseDto(newUser.getName(), token));

        }


        return ResponseEntity.badRequest().build();
    }


}
