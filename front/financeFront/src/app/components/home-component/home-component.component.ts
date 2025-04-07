import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-home-component',
  standalone: false,
  templateUrl: './home-component.component.html',
  styleUrl: './home-component.component.css'
})

export class HomeComponentComponent {
  constructor(private router: Router){}
  
  goToRegister(){
    this.router.navigate(['/register'])
  }

}
