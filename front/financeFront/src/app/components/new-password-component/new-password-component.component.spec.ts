import { ComponentFixture, TestBed } from '@angular/core/testing';

import { NewPasswordComponentComponent } from './new-password-component.component';

describe('NewPasswordComponentComponent', () => {
  let component: NewPasswordComponentComponent;
  let fixture: ComponentFixture<NewPasswordComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [NewPasswordComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(NewPasswordComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
