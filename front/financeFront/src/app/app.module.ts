import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';
import { provideHttpClient, withFetch } from '@angular/common/http'; // Modificação aqui

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponentComponent } from './components/home-component/home-component.component';
import { FooterComponentComponent } from './components/footer-component/footer-component.component';
import { NavComponentComponent } from './components/nav-component/nav-component.component';
import { LoginComponentComponent } from './components/login-component/login-component.component';
import { RegisterComponentComponent } from './components/register-component/register-component.component';
import { RecoveryPasswordComponentComponent } from './components/recovery-password-component/recovery-password-component.component';
import { NewPasswordComponentComponent } from './components/new-password-component/new-password-component.component';
import { SideBarComponentComponent } from './components/side-bar-component/side-bar-component.component';
import { UserPainelComponentComponent } from './components/user-painel-component/user-painel-component.component';
import { MyTransationComponentComponent } from './components/my-transation-component/my-transation-component.component';
import { BuyAndSellStockComponentComponent } from './components/buy-and-sell-stock-component/buy-and-sell-stock-component.component';
import { BuyAndSellCriptoComponentComponent } from './components/buy-and-sell-cripto-component/buy-and-sell-cripto-component.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponentComponent,
    FooterComponentComponent,
    NavComponentComponent,
    LoginComponentComponent,
    RegisterComponentComponent,
    RecoveryPasswordComponentComponent,
    NewPasswordComponentComponent,
    SideBarComponentComponent,
    UserPainelComponentComponent,
    MyTransationComponentComponent,
    BuyAndSellStockComponentComponent,
    BuyAndSellCriptoComponentComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
  ],
  providers: [
    provideHttpClient(withFetch()) 
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }