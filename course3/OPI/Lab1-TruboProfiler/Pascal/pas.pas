program cubicEq;

const n1 : longint = 5;
const n2 : longint = 6;

var amount : longint;
var a, d : real;
var c1, c2 : longint;

function pow(number, exponent : real) : real;
begin
  if number = 0 then begin
    pow := 0;
    exit;
  end;
  pow := Exp(exponent*Ln(number));
end;

function factorial(a : longint) : longint;
var res : longint;
begin
  if a <= 1 then begin
    factorial := 1;
    exit;
  end;

  res := a;
  dec(a);

  while a > 0 do begin
    res := res * a;
    dec(a);
  end;

  factorial := res;
end;

function powWithNeg(n : real; p : real) : real;
begin
  if n < 0 then begin
    powWithNeg := pow(n * -1, p) * -1;
  end  else begin
    powWithNeg := pow(n, p);
  end;
end;

function solveKindOfCubic(a : real; d : real) : string;
var g, p, s, u, x1, x2r, x2i, hsqrt : real;
var sx1, sx2r, sx2i : string;
begin
  g := d / a;

  hsqrt := sqrt(g * g / 4);

  p := 1.0 / 3.0;

  s := -(g / 2) + hsqrt;
  s := powWithNeg(s, p);

  u := -(g / 2) - hsqrt;
  u := powWithNeg(u, p);

  x1 := s + u;

  x2r := -1 * (s + u) / 2;
  x2i := ((s - u) / 2) * pow(3, 0.5);

  str(x1:10:8, sx1);
  str(x2r:10:8, sx2r);
  str(x2i:10:8, sx2i);

  solveKindOfCubic := concat(
    'x1 = ', sx1, ';', #13#10,
    'x2 = ', sx2r, ' + i*', sx2i, ';', #13#10,
    'x3 = ', sx2r, ' - i*', sx2i, ';'
  );
end;

function countEvenColPositiveCells(n : longint; m : longint) : longint;
var i, k, count, v : longint;
begin
  v := 0;
  count := 0;
  k := 1;

  while k <= m do begin

    i := 1;
    while i <= n do begin
      read(v);
      write(v, ' ');

      if i + 1 <= n then begin
        read(v);
        write(v, ' ');
        if v > 0 then count := count + 1;
      end;

        i := i + 2;
    end;

    writeln;
    k := k + 1;    
  end;

  countEvenColPositiveCells := count;
end;


begin
  assign(input,'input.txt');
  reset(input);

  read(amount);
  writeln('Pascal program.');
  writeln(amount, ' matrices');

  while amount > 0 do begin

    dec(amount);

    writeln('T(5, 5)');
    c1 := countEvenColPositiveCells(n1, n1);

    writeln('D(6, 6)');
    c2 := countEvenColPositiveCells(n2, n2);

    writeln;

    writeln('a = ', c1, ';');
    writeln('b = ', c2, ';');

    a := 3 * factorial(c1 + c2);
    d := 2 * factorial(c1);

    writeln('Solving cubic equiation for a = ', a:4:1, '; b = 0.0; c = 0.0; d = ', d:4:1, ';');
    writeln(solveKindOfCubic(a, d));
    writeln;
    writeln;
  end;
end.
