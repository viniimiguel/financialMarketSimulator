import { ComponentFixture, TestBed } from '@angular/core/testing';

import { UserPainelComponentComponent } from './user-painel-component.component';

describe('UserPainelComponentComponent', () => {
  let component: UserPainelComponentComponent;
  let fixture: ComponentFixture<UserPainelComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [UserPainelComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(UserPainelComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
