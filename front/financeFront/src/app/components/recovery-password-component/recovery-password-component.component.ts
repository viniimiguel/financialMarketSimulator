import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-recovery-password-component',
  standalone: false,
  templateUrl: './recovery-password-component.component.html',
  styleUrl: './recovery-password-component.component.css'
})
export class RecoveryPasswordComponentComponent {
  constructor(private router:Router){}


}
