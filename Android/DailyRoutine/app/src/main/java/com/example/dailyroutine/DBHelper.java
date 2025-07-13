package com.example.dailyroutine;

import android.content.Context;

import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;

@Database(entities = {TaskSat.class, TaskSun.class, TaskMon.class, TaskTue.class, TaskWed.class, TaskThu.class, TaskFri.class}, exportSchema = false, version = 1)
public abstract class DBHelper extends RoomDatabase {
    public static final String DB_NAME = "Task_Database";
    private static DBHelper dbInstance;


    public static synchronized DBHelper getDB(Context context){
        if(dbInstance == null){
            dbInstance = Room.databaseBuilder(context, DBHelper.class, DB_NAME)
                    .fallbackToDestructiveMigration()
                    .allowMainThreadQueries()
                    .build();
        }
        return dbInstance;

    }

    public abstract TaskSatDAO taskSatDAO();
    public abstract TaskSunDAO taskSunDAO();
    public abstract TaskMonDAO taskMonDAO();
    public abstract TaskTueDAO taskTueDAO();
    public abstract TaskWedDAO taskWedDAO();
    public abstract TaskThuDAO taskThuDAO();
    public abstract TaskFriDAO taskFriDAO();




}
