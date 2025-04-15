import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-user-painel-component',
  standalone: false,
  templateUrl: './user-painel-component.component.html',
  styleUrls: ['./user-painel-component.component.css']
})
export class UserPainelComponentComponent implements OnInit {
  userName: string = '';

  ngOnInit(): void {
    this.setUserDetails();
  }

  setUserDetails(): void {
    const storedUserName = localStorage.getItem('userName');
    if (storedUserName) {
      this.userName = storedUserName;
      console.log('Usuário carregado do localStorage:', this.userName);
    } else {
      console.warn('Nome do usuário não encontrado no localStorage.');
      this.userName = 'Usuário';
    }
  }
}
