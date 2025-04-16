import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';

interface Stock {
  ticker: string;
  price: number;
}

@Component({
  selector: 'app-buy-and-sell-stock-component',
  standalone: false,
  templateUrl: './buy-and-sell-stock-component.component.html',
  styleUrls: ['./buy-and-sell-stock-component.component.css']
})
export class BuyAndSellStockComponentComponent implements OnInit {
  stocks: Stock[] = [];
  selectedTicker: string = '';
  quantity: number = 1;
  currentBalance: number = 0;
  totalAmountToPay: number = 0;
  totalAmountToReceive: number = 0;

  constructor(private http: HttpClient) {}

  ngOnInit(): void {
    this.fetchStocks();
    this.fetchUserBalance();
  }

  private getAuthHeaders(): HttpHeaders {
    const token = localStorage.getItem('authToken');
    return new HttpHeaders({
      Authorization: `Bearer ${token}`
    });
  }

  fetchStocks(): void {
    const headers = this.getAuthHeaders();
    this.http.get<Stock[]>('http://localhost:8080/api/simulator/stock/all', { headers }).subscribe({
      next: (data) => {
        this.stocks = data;
      },
      error: (err) => {
        console.error('Erro ao buscar ações:', err);
      }
    });
  }

  fetchUserBalance(): void {
    const userId = localStorage.getItem('userId');
    const headers = this.getAuthHeaders();

    this.http.get<{ id: number; balance: number }>(`http://localhost:8080/wallet/get/${userId}`, { headers }).subscribe({
      next: (data) => {
        this.currentBalance = Number(data.balance.toFixed(4));
      },
      error: (error) => {
        console.error('Erro ao obter saldo:', error);
      }
    });
  }

  calculateTotalAmountToPay(): void {
    const selectedStock = this.stocks.find(stock => stock.ticker === this.selectedTicker);
    this.totalAmountToPay = selectedStock ? selectedStock.price * this.quantity : 0;
  }

  calculateTotalAmountToReceive(): void {
    const selectedStock = this.stocks.find(stock => stock.ticker === this.selectedTicker);
    this.totalAmountToReceive = selectedStock ? selectedStock.price * this.quantity : 0;
  }

  buyStock(): void {
    const userId = localStorage.getItem('userId');
    const headers = this.getAuthHeaders();
    const payload = {
      userId,
      ticker: this.selectedTicker,
      quantity: this.quantity
    };

    this.http.post('http://localhost:8080/api/orders/buy', payload, { headers }).subscribe({
      next: (response) => {
        console.log('Compra realizada com sucesso:', response);
        this.fetchUserBalance();
      },
      error: (err) => {
        console.error('Erro ao comprar ação:', err);
        alert('Erro ao realizar compra: ' + (err.error.message || 'Tente novamente.'));
      }
    });
  }

  sellStock(): void {
    const userId = localStorage.getItem('userId');
    const headers = this.getAuthHeaders();
    const payload = {
      userId,
      ticker: this.selectedTicker,
      quantity: this.quantity
    };

    this.http.post('http://localhost:8080/api/orders/sell', payload, { headers }).subscribe({
      next: (response) => {
        console.log('Venda realizada com sucesso:', response);
        this.fetchUserBalance();
      },
      error: (err) => {
        console.error('Erro ao vender ação:', err);
        alert('Erro ao realizar venda: ' + (err.error.message || 'Tente novamente.'));
      }
    });
  }
}
