'use strict'

const AWS = require('aws-sdk');
const s3 = new AWS.S3({
    apiVersion: '2006-03-01'
});

module.exports = {
    // move an object from one s3 bucket to another
    moveObject: async function(source, target, objectName) {
        return new Promise((resolve, reject) =>  {
            // copy it to target...
            s3.copyObject({ Bucket: target, CopySource: `/${ source }/${ objectName }`, Key: objectName }, 
                (err) => {
                    if(err) {
                        reject(err);
                    };
                    // ...then delete it from source
                    this.deleteObject(source, objectName)
                        .then(() => {
                            resolve(true);
                        });
                });
        });
    },
    // delete an s3 object
    deleteObject: async function(bucket, objectName) {
        return new Promise((resolve, reject) =>  {
            s3.deleteObject({ Bucket: bucket, Key: objectName },
                (err) => {
                    if(err) {
                        reject(err);
                        throw err;
                    };
                    resolve(true);
                });
        });
    }
};