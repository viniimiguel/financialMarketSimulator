import { ComponentFixture, TestBed } from '@angular/core/testing';

import { UserLogAndRegComponentComponent } from './user-log-and-reg-component.component';

describe('UserLogAndRegComponentComponent', () => {
  let component: UserLogAndRegComponentComponent;
  let fixture: ComponentFixture<UserLogAndRegComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [UserLogAndRegComponentComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(UserLogAndRegComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
