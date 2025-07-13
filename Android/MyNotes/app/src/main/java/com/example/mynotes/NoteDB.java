package com.example.mynotes;

import android.app.Application;
import android.content.Context;
import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;

@Database(entities = NoteModel.class,version = 1)
public abstract class NoteDB extends RoomDatabase {
    public static final String DB_NAME = "Note_DB";
    public static NoteDB instance;

    public static synchronized NoteDB getInstance(Context context){
        if(instance == null){
            instance = Room.databaseBuilder(context.getApplicationContext(), NoteDB.class,DB_NAME)
                            .fallbackToDestructiveMigration()
                            .allowMainThreadQueries()
                            .build();
        }
        return instance;
    }

    public abstract NoteDao noteDao();


}
