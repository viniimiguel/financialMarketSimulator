import { ComponentFixture, TestBed } from '@angular/core/testing';

import { BuyAndSellCriptoComponentComponent } from './buy-and-sell-cripto-component.component';

describe('BuyAndSellCriptoComponentComponent', () => {
  let component: BuyAndSellCriptoComponentComponent;
  let fixture: ComponentFixture<BuyAndSellCriptoComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [BuyAndSellCriptoComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(BuyAndSellCriptoComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
