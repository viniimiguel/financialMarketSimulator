import { ComponentFixture, TestBed } from '@angular/core/testing';

import { MyTransationComponentComponent } from './my-transation-component.component';

describe('MyTransationComponentComponent', () => {
  let component: MyTransationComponentComponent;
  let fixture: ComponentFixture<MyTransationComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [MyTransationComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(MyTransationComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
