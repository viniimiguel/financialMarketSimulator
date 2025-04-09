import { Component } from '@angular/core';
import { Router, NavigationEnd } from '@angular/router';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  standalone: false,
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'financeFront';
  isSidebarVisible: boolean = false;

  constructor(private router: Router) {}

  ngOnInit(): void {
    this.router.events.subscribe((event) => {
      if (event instanceof NavigationEnd) {
        const routesWithSidebar = ['/user-painel', '/my-transation', '/stock-order', '/cripto-order'];
        this.isSidebarVisible = routesWithSidebar.includes(this.router.url);
      }
    });
  }
}
