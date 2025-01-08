% Input binary data
clc;
clear;
close all;
bits = [1 0 1 1 0]; 
% Parameters
bitrate = 1;  % Bitrate (in bits per second)
n = 1000;     % Number of samples per bit
T = length(bits) / bitrate; % Total time duration
N = n * length(bits); % Total number of samples
dt = T / N;  % Time step size
t = 0:dt:T;  % Time vector

% Initialize the encoded signal (x)
x = zeros(1, length(t));

% Manchester Encoding
for i = 1:length(bits)
    if bits(i) == 1
        % High-to-low transition for '1'
        x((i-1)*n+1:(i-1)*n+n/2) = 1;
        x((i-1)*n+n/2+1:i*n) = -1;
    else
        % Low-to-high transition for '0'
        x((i-1)*n+1:(i-1)*n+n/2) = -1;
        x((i-1)*n+n/2+1:i*n) = 1;
    end
end

% Plot the Manchester Encoded signal
figure;
plot(t, x, 'LineWidth', 3);
title('Manchester Encoded Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

% Decoding
counter = 0;
result = zeros(1, length(bits));  % Initialize result for decoded bits

for i = 1:length(t)
    if t(i) > counter
        counter = counter + 1;
        if x(i) > 0
            result(counter) = 1;  % High-to-low transition indicates '1'
        else
            result(counter) = 0;  % Low-to-high transition indicates '0'
        end
    end
end

% Display the decoded result
disp('Manchester Decoding:');
disp(result);
