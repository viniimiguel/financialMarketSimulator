import { Component, OnInit, OnDestroy, Inject, PLATFORM_ID, ChangeDetectorRef } from '@angular/core';
import { Router } from '@angular/router';
import { isPlatformBrowser } from '@angular/common';

@Component({
  selector: 'app-nav-component',
  standalone: false,
  templateUrl: './nav-component.component.html',
  styleUrls: ['./nav-component.component.css']
})
export class NavComponentComponent implements OnInit, OnDestroy {
  isAuthenticated: boolean = false;
  isBrowser: boolean;

  constructor(
    private router: Router,
    @Inject(PLATFORM_ID) private platformId: Object,
    private cdr: ChangeDetectorRef
  ) {
    this.isBrowser = isPlatformBrowser(platformId);
  }

  ngOnInit() {
    if (this.isBrowser) {
      this.updateAuthStatus();
      window.addEventListener('storage', this.handleStorageChange.bind(this));
    }
  }

  updateAuthStatus() {
    if (this.isBrowser) {
      this.isAuthenticated = !!localStorage.getItem('authToken');
      this.cdr.detectChanges();
    }
  }

  logout() {
    if (this.isBrowser) {
      localStorage.removeItem('authToken');
      localStorage.removeItem('userName');
      localStorage.removeItem('userId');
      this.isAuthenticated = false;

      this.router.navigate(['login']).then(() => {
        this.cdr.detectChanges();
      });
    }
  }

  goToLogin() {
    this.router.navigate(['login']);
  }

  goToRegister() {
    this.router.navigate(['register']);
  }

  handleStorageChange(event: StorageEvent) {
    if (event.key === 'authToken') {
      this.updateAuthStatus();
    }
  }

  ngOnDestroy() {
    if (this.isBrowser) {
      window.removeEventListener('storage', this.handleStorageChange.bind(this));
    }
  }
}
