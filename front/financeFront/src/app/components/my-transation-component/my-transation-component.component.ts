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
  userId = '';
  transactions: Transaction[] = [];
  currentPage = 1;
  itemsPerPage = 10;

  constructor(private http: HttpClient) {}

  ngOnInit(): void {
    const storedUserId = localStorage.getItem('userId');
    if (storedUserId) {
      this.userId = storedUserId;
      this.fetchTransactions();
    }
  }

  fetchTransactions(): void {
    this.http.get<any[]>(`http://localhost:8080/api/orders/get/${this.userId}`).subscribe({
      next: data => {
        this.transactions = data.map(item => ({
          ticker: item.ticker ?? item.symbol ?? 'N/A',
          price: item.price,
          quantity: item.quantity,
          date: new Date(item.timestamp).toLocaleString(),
          type: item.type,
        }));
        this.currentPage = 1;
      },
      error: err => console.error(err)
    });
  }

  get paginatedTransactions(): Transaction[] {
    const start = (this.currentPage - 1) * this.itemsPerPage;
    return this.transactions.slice(start, start + this.itemsPerPage);
  }

  get totalPages(): number {
    return Math.ceil(this.transactions.length / this.itemsPerPage);
  }

  goToPage(page: number): void {
    if (page < 1 || page > this.totalPages) return;
    this.currentPage = page;
  }
}
