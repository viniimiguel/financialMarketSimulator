import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-register-component',
  standalone: false,
  templateUrl: './register-component.component.html',
  styleUrls: ['./register-component.component.css']
})
export class RegisterComponentComponent {
  name: string = '';
  email: string = '';
  password: string = '';
  confPassword: string = '';

  constructor(private router: Router, private http: HttpClient) {}

  register() {
    if (this.password !== this.confPassword) {
      alert('As senhas não coincidem!');
      return;
    }
  
    const registerData = {
      name: this.name,
      email: this.email,
      password: this.password,
      role: 'ROLE_USER'
    };
  
    console.log('Enviando dados de registro:', registerData);
  
    this.http.post('http://localhost:8080/auth/register', registerData)
      .subscribe(
        (response: any) => {
          console.log('Usuário registrado com sucesso:', response);
  
          const walletData = {
            balance: 2000,
            user: { id: response.id }
          };
  
          const headers = { Authorization: `Bearer ${response.token}` };
  
          this.http.post('http://localhost:8080/wallet/create', walletData, { headers })
            .subscribe(
              (walletResponse: any) => {
                console.log('Carteira criada com sucesso:', walletResponse);
                alert('Usuário e carteira criados com sucesso!');
                this.router.navigate(['/login']);
              },
              (walletError) => {
                console.error('Erro ao criar a carteira:', walletError);
                alert('Erro ao criar a carteira: ' + (walletError.error?.message || 'Erro de permissão ou configuração.'));
              }
            );
        },
        (error) => {
          console.error('Erro no registro:', error);
          alert('Erro ao tentar registrar: ' + (error.error.message || 'Tente novamente mais tarde.'));
        }
      );
  }
  
  
}
