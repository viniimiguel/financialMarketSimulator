import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponentComponent } from './components/home-component/home-component.component';
import { LoginComponentComponent } from './components/login-component/login-component.component';
import { RegisterComponentComponent } from './components/register-component/register-component.component';
import { RecoveryPasswordComponentComponent } from './components/recovery-password-component/recovery-password-component.component';
import { NewPasswordComponentComponent } from './components/new-password-component/new-password-component.component';

const routes: Routes = [
  {path: '', component: HomeComponentComponent},
  {path: 'login', component: LoginComponentComponent},
  {path: 'register', component: RegisterComponentComponent},
  {path: 'recovery', component: RecoveryPasswordComponentComponent},
  {path: 'new-password', component: NewPasswordComponentComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
