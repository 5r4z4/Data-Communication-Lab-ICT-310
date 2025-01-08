clc;
clear;
close all;

% Input Parameters
bits = [ 0 1 1 1 0 0 1];  % Binary sequence
bitrate = 1;               % Bitrate in bits per second
n = 1000;                  % Number of samples per bit
T = length(bits) / bitrate; % Total signal duration
N = n * length(bits);      % Total number of samples
dt = T / N;                % Time step for plotting

% Time Vector and Signal Initialization
t = 0:dt:T; 
x = zeros(1, length(t)); 
lastbit = 1;

% NRZ-I Encoding
for i = 1:length(bits)
    if bits(i) == 1
        x((i-1)*n+1:i*n) = -lastbit;  % Flip the voltage for 1
        lastbit = -lastbit;           % Update lastbit
    else
        x((i-1)*n+1:i*n) = lastbit;   % Keep the same voltage for 0
    end
end

% Plot the Encoded Signal
figure;
plot(t, x, 'Linewidth', 3); 
grid on;
title('NRZ-I Encoding');
xlabel('Time (s)');
ylabel('Amplitude');

% NRZ-I Decoding
result = zeros(1, length(bits));  % Pre-allocate result array
counter = 0; 
lastbit = 1;

for i = 1:length(t)
    if mod(i, n) == 1  % Check at the beginning of each bit interval
        counter = counter + 1; 
        if x(i) ~= lastbit
            result(counter) = 1;  % Voltage change indicates 1
            lastbit = -lastbit;   % Update lastbit
        else
            result(counter) = 0;  % No voltage change indicates 0
        end
    end
end

% Display Decoded Bits
disp('NRZ-I Decoding:'); 
disp(result);
