import numpy as np

nw = 11091  # warmup total iterations
ni_list = [3697, 7394, 11091]  # epoch 1,2,3 첫 iteration 위치

# baseline warmup lr 값 그대로 하드코딩 scaling
lr_values = [0.0033261, 0.0066463, 0.0099532]

print(lr_values)