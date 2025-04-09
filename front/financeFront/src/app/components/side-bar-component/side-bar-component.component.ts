import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-side-bar-component',
  standalone: false,
  templateUrl: './side-bar-component.component.html',
  styleUrls: ['./side-bar-component.component.css']
})
export class SideBarComponentComponent implements OnInit {
  selectedLink: string = '';

  constructor(private router: Router) {}

  ngOnInit(): void {
    this.selectedLink = this.getCurrentRoute();

    this.router.events.subscribe(() => {
      this.selectedLink = this.getCurrentRoute();
    });
  }

  selectLink(link: string): void {
    this.selectedLink = link;
    this.router.navigateByUrl(link); 
  }

  private getCurrentRoute(): string {
    const routeMap: { [key: string]: string } = {
      '/user-painel': 'Minha carteira',
      '/my-transation': 'Transações',
      '/stock-order': 'Comprar e vender ações',
      '/cripto-order': 'Comprar e vender criptos'
    };

    return routeMap[this.router.url] || '';
  }
}
