import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RecoveryPasswordComponentComponent } from './recovery-password-component.component';

describe('RecoveryPasswordComponentComponent', () => {
  let component: RecoveryPasswordComponentComponent;
  let fixture: ComponentFixture<RecoveryPasswordComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [RecoveryPasswordComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(RecoveryPasswordComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
