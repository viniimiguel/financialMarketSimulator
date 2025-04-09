import { ComponentFixture, TestBed } from '@angular/core/testing';

import { BuyAndSellStockComponentComponent } from './buy-and-sell-stock-component.component';

describe('BuyAndSellStockComponentComponent', () => {
  let component: BuyAndSellStockComponentComponent;
  let fixture: ComponentFixture<BuyAndSellStockComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [BuyAndSellStockComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(BuyAndSellStockComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
