import numpy as np
import numpy.ma as ma
import pandas as pd
import tensorflow as tf
from tensorflow import keras
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn.model_selection import train_test_split
import tabulate
from recsysNN_utils import *
pd.set_option("display.precision", 1)


top10_df = pd.read_csv("./C3_W2/data2/content_top10_df.csv")
bygenre_df = pd.read_csv("./C3_W2/data2/content_bygenre_df.csv")
print(top10_df)
print("\n")
print(bygenre_df)




item_train, user_train, y_train, item_features, user_features, item_vecs, movie_dict, user_to_genre = load_data()

print("\nitem/movie features: ", item_features)
print("\nuser features: ", user_features)
num_item_features = item_train.shape[1] - 1  # remove movie id at train time
num_user_features = user_train.shape[1] - 3  # remove userid, rating count and ave rating during training
uvs = 3  # user genre vector start
ivs = 3  # item genre vector start
u_s = 3  # start of columns to use in training, user
i_s = 1  # start of columns to use in training, items
print(f"Number of training vectors: {len(item_train)}")
print(f"Number of user vectors: {len(user_train)}")
print("\nitem_train shape: ", item_train.shape)
print("user_train shape: ", user_train.shape)
print("y.shape: ", y_train.shape)



pprint_train(user_train, user_features, uvs,  u_s, maxcount=5)

pprint_train(item_train, item_features, ivs, i_s, maxcount=5, user=False)

print(f"y_train[:5]: {y_train[:5]}")


print("\n\n")


item_train_unscaled = item_train
user_train_unscaled = user_train
y_train_unscaled    = y_train

scalerItem = StandardScaler()
scalerItem.fit(item_train)
item_train = scalerItem.transform(item_train)

scalerUser = StandardScaler()
scalerUser.fit(user_train)
user_train = scalerUser.transform(user_train)

scalerTarget = MinMaxScaler((-1, 1))
scalerTarget.fit(y_train.reshape(-1, 1))
y_train = scalerTarget.transform(y_train.reshape(-1, 1))
#ynorm_test = scalerTarget.transform(y_test.reshape(-1, 1))

print(np.allclose(item_train_unscaled, scalerItem.inverse_transform(item_train)))
print(np.allclose(user_train_unscaled, scalerUser.inverse_transform(user_train)))





item_train, item_test = train_test_split(item_train, train_size=0.80, shuffle=True, random_state=1)
user_train, user_test = train_test_split(user_train, train_size=0.80, shuffle=True, random_state=1)
y_train, y_test       = train_test_split(y_train,    train_size=0.80, shuffle=True, random_state=1)
print(f"\nmovie/item training data shape: {item_train.shape}")
print(f"movie/item test data shape: {item_test.shape}")

pprint_train(user_train, user_features, uvs, u_s, maxcount=5)






num_outputs = 32
tf.random.set_seed(1)
user_NN = tf.keras.models.Sequential([
    ### START CODE HERE ###     
    tf.keras.layers.Dense(256,activation='relu'),
    tf.keras.layers.Dense(128,activation='relu'),
    tf.keras.layers.Dense(32)
    ### END CODE HERE ###  
])

item_NN = tf.keras.models.Sequential([
    ### START CODE HERE ###     
    tf.keras.layers.Dense(256,activation='relu'),
    tf.keras.layers.Dense(128,activation='relu'),
    tf.keras.layers.Dense(32)
    ### END CODE HERE ###  
])

# create the user input and point to the base network
input_user = tf.keras.layers.Input(shape=(num_user_features,))
vu = user_NN(input_user)
vu = tf.linalg.l2_normalize(vu, axis=1) #produces error

# create the item input and point to the base network
input_item = tf.keras.layers.Input(shape=(num_item_features,))
vm = item_NN(input_item)
vm = tf.linalg.l2_normalize(vm, axis=1) #produces error

# compute the dot product of the two vectors vu and vm
output = tf.keras.layers.Dot(axes=1)([vu, vm])

# specify the inputs and output of the model
model = tf.keras.Model([input_user, input_item], output)

model.summary()
