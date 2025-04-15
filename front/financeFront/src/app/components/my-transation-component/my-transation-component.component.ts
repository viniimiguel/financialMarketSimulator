import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';

interface Transaction {
  ticker: string;
  price: number;
  quantity: number;
  date: string;
  type: string;
}

@Component({
  selector: 'app-my-transation-component',
  standalone: false,
  templateUrl: './my-transation-component.component.html',
  styleUrls: ['./my-transation-component.component.css']
})
export class MyTransationComponentComponent implements OnInit {
  userId: string = '';
  transactions: Transaction[] = [];

  constructor(private http: HttpClient) {}

  ngOnInit(): void {
    this.fetchUserId();
  }

  fetchUserId(): void {
    const storedUserId = localStorage.getItem('userId');
    if (storedUserId) {
      this.userId = storedUserId;
      console.log('ID do usuário carregado do localStorage:', this.userId);
      this.fetchTransactions();
    } else {
      console.warn('ID do usuário não encontrado no localStorage.');
    }
  }

  fetchTransactions(): void {
    this.http.get<any[]>(`http://localhost:8080/api/orders/get/${this.userId}`).subscribe({
      next: (data) => {
        console.log('Dados de transações recebidos:', data);
        this.transactions = data.map((item) => ({
          ticker: item.ticker ?? item.symbol ?? 'N/A',
          price: item.price,
          quantity: item.quantity,
          date: new Date(item.timestamp).toLocaleString(),
          type: item.type,
        }));
        console.log('Transações formatadas:', this.transactions);
      },
      error: (err) => {
        console.error('Erro ao buscar transações:', err);
      }
    });
  }
}
