package com.kim.android_study_ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("android_study_ndk");
    }

    public static native String getStringFromJNI();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tvjni = (TextView) findViewById(R.id.tv_jni);
        tvjni.setText(getStringFromJNI());
    }
}
