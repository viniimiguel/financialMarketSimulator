import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-login-component',
  standalone: false,
  templateUrl: './login-component.component.html',
  styleUrls: ['./login-component.component.css']
})
export class LoginComponentComponent {
  email: string = '';
  password: string = '';

  constructor(private router: Router, private http: HttpClient) {}

  login() {
    const loginData = {
      email: this.email,
      password: this.password
    };

    console.log('Enviando dados de login:', loginData);

    this.http.post('http://localhost:8080/auth/login', loginData)
      .subscribe(
        (response: any) => {
          console.log('Resposta do servidor:', response);
          localStorage.setItem('authToken', response.token);
          localStorage.setItem('userName', response.name);
          this.router.navigate(['/user-painel']);
        },
        (error) => {
          console.error('Erro no login:', error);
          alert('Erro ao tentar fazer login: ' + (error.error.message || 'Verifique suas credenciais'));
        }
      );
  }
}
