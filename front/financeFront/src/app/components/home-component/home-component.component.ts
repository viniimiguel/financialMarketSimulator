import { Component, OnInit, OnDestroy } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';

interface Stock {
  ticker: string;
  price: number;
  variation: number;
}

interface Notice {
  title: string;
  content: string;
}

@Component({
  selector: 'app-home-component',
  standalone: false,
  templateUrl: './home-component.component.html',
  styleUrls: ['./home-component.component.css']
})
export class HomeComponentComponent implements OnInit, OnDestroy {
  allStocks: Stock[] = [];
  displayedStocks: Stock[] = [];
  notice: Notice | null = null;
  private stockIndex = 0;

  constructor(private router: Router, private http: HttpClient) {}

  ngOnInit(): void {
    this.http.get<Stock[]>('http://localhost:8080/api/simulator/stock/random').subscribe({
      next: (data: any[]) => {
        console.log('Dados recebidos da API:', data);
        if (!Array.isArray(data)) {
          console.error('Resposta da API não é um array');
          return;
        }

        this.allStocks = data
          .filter(stock => stock?.ticker && stock?.price != null && stock?.variation != null)
          .map(stock => ({
            ticker: stock.ticker,
            price: stock.price,
            variation: stock.variation
          }));

        console.log('Ações filtradas:', this.allStocks);

        if (this.allStocks.length > 0) {
          this.updateDisplayedStocks();
        }
      },
      error: (err) => {
        console.error('Erro ao buscar ações da API:', err);
      }
    });

    this.http.get('http://localhost:8080/api/groq/get/notice', { responseType: 'text' }).subscribe({
      next: (data) => {
        this.notice = { title: 'Notícia', content: data }; 
      },
      error: (err) => console.error('Erro ao buscar notícia da API:', err)
    });
  }

  ngOnDestroy(): void {}

  updateDisplayedStocks(): void {
    const total = this.allStocks.length;

    if (total === 0) {
      console.warn('Nenhuma ação disponível para exibir.');
      return;
    }

    this.displayedStocks = [];

    for (let i = 0; i < 4; i++) {
      const index = (this.stockIndex + i) % total;
      this.displayedStocks.push(this.allStocks[index]);
    }

    this.stockIndex = (this.stockIndex + 4) % total;
  }

  goToRegister(): void {
    this.router.navigate(['/register']);
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
}