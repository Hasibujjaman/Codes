package com.example.roomlibraryexample;

import android.content.Context;

import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;

@Database(entities = Expense.class, exportSchema = false, version = 1)
public abstract class DBHelper extends RoomDatabase {
    private static final String DB_NAME = "Database_1";
    private static DBHelper instance;

    public static synchronized DBHelper getDB(Context context){
        if(instance == null){
            instance = Room.databaseBuilder(context, DBHelper.class, DB_NAME)
                    .fallbackToDestructiveMigration()
                    .allowMainThreadQueries()
                    .build();
        }
        return instance;
    }

    public abstract ExpenseDAO expenseDAO();


}
