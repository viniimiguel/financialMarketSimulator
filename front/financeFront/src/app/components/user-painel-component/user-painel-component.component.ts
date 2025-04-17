import { Component, OnInit, OnDestroy, ChangeDetectorRef } from '@angular/core';
import { HttpClient } from '@angular/common/http';

interface Stock {
  ticker: string;
  price: number;
  variation: number;
  quantity?: number;
}

interface Notice {
  title: string;
  content: string;
}

@Component({
  selector: 'app-user-painel',
  standalone: false,
  templateUrl: './user-painel-component.component.html',
  styleUrls: ['./user-painel-component.component.css']
})
export class UserPainelComponentComponent implements OnInit, OnDestroy {
  userName: string = '';
  userId: string = '';
  allStocks: Stock[] = [];
  myWallet: { ticker: string; quantity: number }[] = [];
  currentBalance: number = 0;
  estimatedBalance: number = 0;
  showingStocks: boolean = true;
  notice: Notice | null = null;

  private stockEventSource: EventSource | null = null;

  constructor(private http: HttpClient, private cdr: ChangeDetectorRef) {}

  ngOnInit(): void {
    this.setUserDetails();
    this.fetchUserId();
    this.fetchNotice();
    this.fetchWalletBalance();
    this.initSSEConnection();
  }

  ngOnDestroy(): void {
    if (this.stockEventSource) {
      this.stockEventSource.close();
    }
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

  fetchUserId(): void {
    const storedUserId = localStorage.getItem('userId');
    if (storedUserId) {
      this.userId = storedUserId;
      console.log('ID do usuário carregado do localStorage:', this.userId);
      this.fetchWalletData();
    } else {
      console.warn('ID do usuário não encontrado no localStorage.');
    }
  }

  fetchWalletData(): void {
    this.http.get<{ ticker: string; quantity: number }[]>(`http://localhost:8080/wallet/get/my-wallet/${this.userId}`).subscribe({
      next: (data) => {
        console.log('Dados da carteira:', data);
        this.myWallet = data;
        this.fetchStockData(); 
      },
      error: (err) => {
        console.error('Erro ao buscar dados da carteira:', err);
      }
    });
  }

  fetchStockData(): void {
    this.http.get<Stock[]>('http://localhost:8080/api/simulator/stock/all').subscribe({
      next: (data: any[]) => {
        console.log('Dados recebidos da API:', data);
        if (!Array.isArray(data)) {
          console.error('Resposta da API não é um array');
          return;
        }

        this.allStocks = this.myWallet
          .map(walletItem => {
            const stockData = data.find(stock => stock.ticker === walletItem.ticker);
            return stockData
              ? {
                  ticker: stockData.ticker,
                  price: stockData.price,
                  variation: stockData.variation,
                  quantity: walletItem.quantity
                }
              : null;
          })
          .filter(stock => stock !== null) as Stock[];

        this.calculateEstimatedBalance();
      },
      error: (err) => {
        console.error('Erro ao buscar ações da API:', err);
      }
    });
  }

  initSSEConnection(): void {
    this.stockEventSource = new EventSource('http://localhost:8080/api/simulator/stock/all');

    this.stockEventSource.onmessage = (event) => {
      const data = JSON.parse(event.data);

      if (!Array.isArray(data)) return;

      this.allStocks = this.myWallet
        .map(walletItem => {
          const stockData = data.find(stock => stock.ticker === walletItem.ticker);
          return stockData
            ? {
                ticker: stockData.ticker,
                price: stockData.price,
                variation: stockData.variation,
                quantity: walletItem.quantity
              }
            : null;
        })
        .filter(stock => stock !== null) as Stock[];

      this.calculateEstimatedBalance();
      this.cdr.detectChanges();
    };

    this.stockEventSource.onerror = (error) => {
      console.error('Erro no SSE:', error);
      if (this.stockEventSource) {
        this.stockEventSource.close();
      }
    };
  }

  fetchWalletBalance(): void {
    this.http.get<{ id: number; balance: number }>(`http://localhost:8080/wallet/get/${this.userId}`).subscribe({
      next: (data) => {
        this.currentBalance = data.balance;
        console.log('Saldo atual carregado:', this.currentBalance);
      },
      error: (err) => {
        console.error('Erro ao buscar saldo atual:', err);
      }
    });
  }

  calculateEstimatedBalance(): void {
    this.estimatedBalance = this.allStocks.reduce((total, stock) => {
      return total + (stock.price * (stock.quantity || 0));
    }, 0);
    console.log('Saldo estimado calculado:', this.estimatedBalance);
  }

  fetchNotice(): void {
    this.http.get('http://localhost:8080/api/groq/get/notice', { responseType: 'text' }).subscribe({
      next: (data) => {
        const cleanedContent = data.replace(/nn/g, '\n');
        const titleMatch = cleanedContent.match(/\*\*(.*?)\*\*/);
        const title = titleMatch ? titleMatch[1] : 'Notícia';
        const content = cleanedContent.replace(/\*\*(.*?)\*\*/, '').trim();
        this.notice = { title, content };
      },
      error: (err) => {
        console.error('Erro ao buscar notícia da API:', err);
      }
    });
  }

  getFormattedVariation(variation: number | undefined): string {
    if (variation === undefined || variation === null) {
      return '';
    }
    const formatted = variation.toFixed(2);
    return `${variation >= 0 ? '+' : ''}${formatted}%`;
  }

  getVariationClass(variation: number | undefined): string {
    if (variation === undefined || variation === null) return '';
    return variation >= 0 ? 'positive' : 'negative';
  }

  addBalance(amount: number): void {
    this.currentBalance += amount;
    console.log(`Saldo atual atualizado: ${this.currentBalance}`);
  }

  showStocks(): void {
    this.showingStocks = true;
    console.log('Mostrando Ações');
  }

  showCryptos(): void {
    this.showingStocks = false;
    console.log('Mostrando Criptomoedas');
  }
}
