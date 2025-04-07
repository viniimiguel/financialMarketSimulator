import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-nav-component',
  standalone: false,
  templateUrl: './nav-component.component.html',
  styleUrl: './nav-component.component.css'
})
export class NavComponentComponent {
  constructor(private router:Router){}

  goToLogin(){
    this.router.navigate(['login'])
  }
  goToRegister(){
    this.router.navigate(['register'])
  }

}
