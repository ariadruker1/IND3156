      program meeus1
c
      integer j
      integer x
c
      x = 1
      j = 0
30    x = 2*x
      if ( j .lt. 130 ) goto 60
!      if ( x+1 .ne. x ) goto 60
50    goto 80
60    j = j + 1
      write(6,*) ' j=', j, ', 10s=', j*log10(2.), ',  x=', x
70    goto 30
80    continue

c
      stop
      end
